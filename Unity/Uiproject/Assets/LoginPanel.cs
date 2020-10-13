using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class LoginPanel : MonoBehaviour
{
    public Button btn_Return;
    public Button btn_Login;
    public GameObject enterPanel;
    public InputField inf_Usr;
    public InputField inf_Code;
    // Start is called before the first frame update
    void Start()
    {
        btn_Return.onClick.AddListener(ReturnUI);
        btn_Login.onClick.AddListener(Login);
    }
    private void ReturnUI()
    {
        //Debug.Log("返回上一界面");
        enterPanel.SetActive(true);
        this.gameObject.SetActive(false);
    }
    private void Login()
    {
        if(inf_Usr.text=="admin"&&inf_Code.text=="zwy5201314")
        {
            Debug.Log("登陆成功");
        }
        else
        {
            Debug.Log("登陆失败");
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
