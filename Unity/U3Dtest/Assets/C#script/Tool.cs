using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tool : MonoBehaviour
{
    //封装显示特效
    public static void PlayEffect(GameObject go,Vector3 ps,Quaternion rs)
    {
        Instantiate(go,ps,rs);
    }
}
