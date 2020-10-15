﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
//碰撞检测
//碰撞的条件
//1、两个发生碰撞的物体，两个物体都需要有刚体或者至少一个物体有刚体
//一般情况下，两个都带有刚体的物体相互发生碰撞或者有刚体的碰撞没有刚体的
//2、两个相互碰撞的物体都必须有碰撞体
public class Test : MonoBehaviour
{
    #region 以下是碰撞检测

    //private void OnCollisionEnter(Collision collision)
    //{
    //    Debug.Log("Cube1碰撞到了" + collision.gameObject.name);
    //}
    //private void OnCollisionStay(Collision collision)
    //{
    //    Debug.Log("碰撞停留，碰撞到了" + collision.gameObject.name);
    //}
    //private void OnCollisionExit(Collision collision)
    //{
    //    Debug.Log("碰撞退出，碰撞到了" + collision.gameObject.name);
    //}
    #endregion
    #region 以下是触发检测
    private void OnTriggerEnter(Collider other)
    {
        Debug.Log("触发进入，碰撞到了" + other.name);
    }
    private void OnTriggerStay(Collider other)
    {
        Debug.Log("触发停留，碰撞到了" + other.name);
    }
    private void OnTriggerExit(Collider other)
    {
        Debug.Log("触发退出，碰撞到了" + other.name);
    }
    #endregion

}