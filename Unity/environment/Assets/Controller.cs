using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//Unity的生命周期函数
//1、继承与MonoBehaviour的脚本才能挂载在物体上，只有继承了MonoBehaviour才能使用生命周期
//2、当脚本所挂载的物体被隐藏时，那么脚本就无法运行
//3、当脚本禁用的时候，Awake依然会被执行一次

public class Controller : MonoBehaviour
{
    // Start is called before the first frame update
    private void Awake()//Awake 函数只调用一次，物体被唤醒的时候调用，只要物体被唤醒，那么就会调用Awake函数
    {
        Debug.Log("这是Awake函数");
    }
    void Start()//Start函数只被调用一次
    {
        
    }

    // Update is called once per frame
    void Update()//Update函数每帧都会调用一次，一直被调用 
    {
        
    }
}
