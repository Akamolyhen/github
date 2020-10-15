using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tool : MonoBehaviour
{
    private Dictionary<string, GameObject> dicPrefab = new Dictionary<string, GameObject>();
    //封装生成物体或特效
    public static void InstantiateObj(string path,Vector3 ps,Quaternion rs)
    {
        //Instantiate(go, ps, rs);GameObject go

        GameObject go = Resources.Load<GameObject>(path);
        Instantiate(go, ps, rs);
    }
}
