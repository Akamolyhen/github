using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FemCtrl : MonoBehaviour
{
    private Animator ani;
    //标志是否可以接连招
    private bool IsCanSkill = false;
    // Start is called before the first frame update
    void Start()
    {
        ani = this.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        AnimatorStateInfo aniInfo= ani.GetCurrentAnimatorStateInfo(0);
        if (Input.GetKey(KeyCode.W))
        {
            ani.SetBool("Walk", true);
        }
        else
        {
            ani.SetBool("Walk", false);
        }
        if(Input.GetMouseButtonDown(0)&& aniInfo.IsName("CombatModeA"))
        {
            ani.SetTrigger("Shot_Straight");
        }
        if(aniInfo.IsName("Shot_Straight") &&IsCanSkill)
        {
            if(Input.GetKeyDown(KeyCode.K))
            {
                ani.SetTrigger("Magic_Helix_Spell");
            }
        }
        //通过normalizedTime动画播放时间
        //if(aniInfo.IsName("Shot_Straight")&&(aniInfo.normalizedTime>0.3f&& aniInfo.normalizedTime <0.7f))
        //{
        //    if (Input.GetKeyDown(KeyCode.K))
        //    {
        //        ani.SetTrigger("Magic_Helix_Spell");
        //    }
        //}
        CanDying();
    }
    void MagicStart()
    {
        IsCanSkill = true;
    }
    void MagicEnd()
    {
        IsCanSkill = false;
    }
    private void CanDying()
    {
        if(Input.GetKeyDown(KeyCode.D))
        {
            ani.SetTrigger("Dying");
        }
    }
}
