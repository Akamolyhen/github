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
    //攻击距离
    private float AttackDis = 7;
    //敌人的位置，通过查找找到
    private GameObject Enemy;
    private GameObject Effect;
    //蜘蛛与敌人的位置向量差
    private Vector3 offset;
    // Start is called before the first frame update
    void Start()
    {
        ani = this.GetComponent<Animator>();
        Enemy = GameObject.FindGameObjectWithTag("Enemy");
        Effect = Resources.Load<GameObject>("Effect");
    }

    // Update is called once per frame
    void Update()
    {
        SpiderTranslate();
        SpiderAttack();
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
    private void SpiderAttack()
    {
        if(Input.GetMouseButtonDown(0))
        {
            
            if (Vector3.Distance(this.transform.position, Enemy.transform.position) <= AttackDis)
            {
                offset = Enemy.transform.position - this.transform.position;
                float angle = Vector3.Angle(this.transform.forward, offset);
                if(angle<=15)
                {
                    this.transform.LookAt(Enemy.transform.position);
                    //延时销毁
                    Invoke(nameof(EnemyDestroy), 1f); 
                }
               
            }
            ani.SetTrigger("Attack");

        }
        
    }
    private void EnemyDestroy()
    {
        Instantiate(Effect, Enemy.transform.position, Quaternion.identity);
        Destroy(Enemy);
    }
}
