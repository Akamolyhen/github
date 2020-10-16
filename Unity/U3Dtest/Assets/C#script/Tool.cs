using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tool : MonoBehaviour
{
    private Tool()
    {

    }
    private static Tool instance;
    public static Tool Instance
    {
        get
        {
            if (instance == null)
            {
                instance = new Tool();
            }
            return instance;
        }
    }
    
    private Dictionary<string, GameObject> dicPrefab = new Dictionary<string, GameObject>();
    //封装生成物体或特效
    public  void InsObj(string path,Vector3 ps,Quaternion rs) //预制体路径，预制体生成位置，预制体生成时候的旋转方向
    {
        GameObject go = LoadObj(path);
        //生成这个物体
        Instantiate(go, ps, rs);
        
       
    }
    public GameObject LoadObj(string path)
    {
        GameObject go;

        if (dicPrefab.ContainsKey(path))
        {
            go = dicPrefab[path];
        }
        else
        {
            go = Resources.Load<GameObject>(path);
            dicPrefab.Add(path, go);
        }
        return go;
    }
}
