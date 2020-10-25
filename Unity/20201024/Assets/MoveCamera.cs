using System.Collections;
using System.Collections.Generic;
using HedgehogTeam.EasyTouch;
using UnityEngine;

public class MoveCamera : MonoBehaviour
{
    private float speed = 50;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Gesture current = EasyTouch.current;
        if(current.type==EasyTouch.EvtType.On_Swipe&&current.touchCount==1)
        {
            transform.Translate(Vector3.left * current.deltaPosition.x / Screen.width*speed);
            transform.Translate(Vector3.back * current.deltaPosition.y / Screen.height*speed);
        }
    }
}
