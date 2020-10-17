using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChanCtrl : MonoBehaviour
{
    private Animator ani;
    // Start is called before the first frame update
    void Start()
    {
        ani = this.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        AnimatorStateInfo aniInfo = ani.GetCurrentAnimatorStateInfo(0);
        if(Input.GetKey(KeyCode.W))
        {
            ani.SetBool("RUN00_F", true);
        }
        else
        {
            ani.SetBool("RUN00_F", false);
           
        }
        if (Input.GetKeyDown(KeyCode.Space) && aniInfo.IsName("WAIT01"))
        {
            ani.SetTrigger("JUMP00");
        }
    }
}
