using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//Unity的生命周期函数
//1、继承与MonoBehaviour的脚本才能挂载在物体上，只有继承了MonoBehaviour才能使用生命周期
//2、当脚本所挂载的物体被隐藏时，那么脚本就无法运行
//3、如果脚本是禁用状态，Awake依然会被执行一次,其他的生命周期函数不会被执行
//4、所有的生命周期函数都是在物体被唤醒后才能调用
public class Controller : MonoBehaviour
{
    // Start is called before the first frame update
    private void Awake()//Awake 函数只调用一次，在物体第一次被唤醒的时候调用，只要物体被唤醒，那么就会调用Awake函数
                        //之后隐藏在唤醒，不会再调用Awake函数
    {
        Debug.Log("这是Awake函数");
    }
    //物体显示出来的瞬间会被调用
    private void OnEnable()
    {
        Debug.Log("这是onEnable函数");
    }
    void Start()//Start函数只被调用一次
    {
        Debug.Log("这是Start函数");
    }

   // Update is called once per frame
    void Update()//Update函数每帧都会调用一次，一直被调用 
    {
        //每秒被执行多少帧不能确定，取决于机器的性能
        Debug.Log("这是Update函数");
    }
   // 固定帧更新（）//固定的每秒会被执行多少次
    private void FixedUpdate()
    {
        Debug.Log("这是Fixedupdate函数");
    }
    private void LateUpdate()//LateUpdate每帧都会调用一次，在Update执行后调用
    {
        Debug.Log("这是Lateupdate函数");  
    }
    private void OnGUI()
    {
        Debug.Log("这是OnGUI函数");
        if (GUI.Button(new Rect(0, 0, 50, 30), "确定"))
        {
            Debug.Log("按钮被单击");
        }
        GUI.Label(new Rect(100, 100, 100, 50), "这是Label");
    }
    private void OnDisable()
    {
        Debug.Log("这是OnDisable函数");//当物体被隐藏时被调用
    }
    private void OnDestroy()
    {
        Debug.Log("这是OnDestroy函数");//当物体被销毁时被调用
    }
}
