using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform target;
    private float smooth = 100f;
    //偏移量
    private Vector3 offset;
    

    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.Find("Tank").transform;
        offset = this.transform.position - target.position;
        
    }

    // Update is called once per frame
    void Update()
    {
        if (target)
        {
            Vector3 targetPs = target.position + offset;
            this.transform.position = Vector3.Lerp(this.transform.position, targetPs, smooth);
        }
    }
}
