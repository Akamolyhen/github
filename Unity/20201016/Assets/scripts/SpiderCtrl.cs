using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class SpiderCtrl : MonoBehaviour
{
    private Animator ani;
    //转向的速度
    private float rotatespeed = 100;
    //移动的速度
    private float translatespeed = 10;
    // Start is called before the first frame update
    void Start()
    {
        ani = this.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        SpiderTranslate();
    }
    private void SpiderRotate()//蜘蛛转向
    {
        if(Input.GetKey(KeyCode.A)||Input.GetKey(KeyCode.D))
        {
            float h = Input.GetAxis("Horizontal");
            Vector3 rotate = new Vector3(0, h * rotatespeed * Time.deltaTime, 0);
            this.transform.Rotate(rotate);
            ani.SetBool("Walk", true);
        }
        else
        {
            ani.SetBool("Walk", false);
        }
       
    }
    private void SpiderRun()
    {
        if(Input.GetKey(KeyCode.W)||Input.GetKey(KeyCode.S))
        {
            float v = Input.GetAxis("Vertical");
            Vector3 translate = new Vector3(0, 0, v * Time.deltaTime * translatespeed);
            this.transform.Translate(translate);
            ani.SetBool("Run", true);
        }
        else
        {
            ani.SetBool("Run", false);
        }
    }
    private void SpiderTranslate()
    {
        SpiderRotate();
        SpiderRun();
    }
}
