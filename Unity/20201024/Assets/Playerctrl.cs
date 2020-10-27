using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Playerctrl : MonoBehaviour
{
    private CharacterController cc;//默认角色自带刚体属性
    private Animator ani;
    public bool isCanMove = true;
    private Button btn_win;
    // Start is called before the first frame update
    void Start()
    {
        cc = GetComponentInChildren<CharacterController>();
        ani = GetComponent<Animator>();
        btn_win = GameObject.Find("Canvas/Atk_Button").GetComponent<Button>();
        btn_win.onClick.AddListener(Win);
    }

    // Update is called once per frame
    void Update()
    {
        if (ani.GetCurrentAnimatorStateInfo(0).IsName("WIN00"))
        {
            isCanMove = false;
        }
        else
            isCanMove = true;
        if((ETCInput.GetAxis("Vertical")!=0)||ETCInput.GetAxis("Horizontal")!=0)
        {
            ani.SetBool("Run",true);
        }
        if ((ETCInput.GetAxis("Vertical") == 0) && ETCInput.GetAxis("Horizontal") == 0)
        {
            ani.SetBool("Run", false);
        }
    }
    private void Win()
    {
        ani.SetTrigger("Win");
       
    }
}
