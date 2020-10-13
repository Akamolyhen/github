using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnterPanel : MonoBehaviour
{
    public Button btn_Enter;
    // Start is called before the first frame update
    //start 在物体显示出来自动调用一次
    void Start()
    {
        btn_Enter.onClick.AddListener(ShowLoginPanel);
    }
    private void ShowLoginPanel()
    {
        Debug.Log("登陆按钮被单击");
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
