
using System.Collections;
using System.Collections.Generic;
using HedgehogTeam.EasyTouch;
using UnityEditor.Android;
using UnityEngine;

public class EasyTouchCtrl : MonoBehaviour
{
    QuickTouch[] arrQt;
    //QuickTap qtap;
    private void Start()
    {
        arrQt = GetComponents<QuickTouch>();
        arrQt[0].onTouch.AddListener(StartFun);
        arrQt[1].onTouch.AddListener(DownFun);
        arrQt[2].onTouch.AddListener(UpFun);
        arrQt[2].onTouchNotOverMe.AddListener(Touchoverme);

        //    qtap = GetComponent<QuickTap>();
        //    qtap.onTap.AddListener(SimTap);
        //
    }
    private void StartFun(Gesture gesture)
    {
        RandomColor();
        Debug.Log("单击物体的瞬间" + gesture.pickedObject.name);
    }
    private void RandomColor()
    {
        gameObject.GetComponent<Renderer>().material.color = new Color(Random.Range(0.0f, 1.0f), Random.Range(0.0f, 1.0f), Random.Range(0.0f, 1.0f));
    }
    private void DownFun(Gesture gesture)
    {
        Debug.Log(gesture.actionTime);
    }
   private void UpFun(Gesture gesture)
    {
        RandomColor();
        Debug.Log("抬起物体的瞬间" + gesture.pickedObject.name);
    }
    private void Touchoverme(Gesture gesture)
    {
        Debug.Log("鼠标不再我身上抬起的瞬间");
    }
    //private void SimTap(Gesture gesture)
    //{
    //    Debug.Log("单击");
    //}
}
