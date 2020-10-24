using System.Collections;
using System.Collections.Generic;
using HedgehogTeam.EasyTouch;
using UnityEngine;

public class CubeTap : MonoBehaviour
{
    QuickTap qtap;
    // Start is called before the first frame update
    void Start()
    {
        qtap = GetComponent<QuickTap>();
        qtap.onTap.AddListener(SimTap);
    }
    private void SimTap(Gesture gesture)
    {
        RandomColor();
        Debug.Log("单击");
    }
    private void RandomColor()
    {
        GetComponent<Renderer>().material.color = new Color(Random.Range(0.0f, 0.1f), Random.Range(0.0f, 0.1f), Random.Range(0.0f, 0.1f));
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
