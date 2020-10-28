using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class Herocontrol : MonoBehaviour
{
    //角色是否已经死亡
    private bool isDie = false;
    private Animator ani;
    private float movespeed = 10f;
    private float Jspeed = 800f;private float Jspeed2 =900f;
   
    private E_Direction dir = E_Direction.Left;
    private int Jumpcount = 2;
    private bool isGround = true;
    private bool isJump = false;
    private bool m_jump = true;
    //当前动画层播放信息
    private AnimatorStateInfo info;
    private EnemyManager enemyMgr;
    // Start is called before the first frame update
    void Start()
    {
        enemyMgr = GameObject.Find("EnemyManager").GetComponent<EnemyManager>();
        ani = GetComponent<Animator>();
        
    }

    // Update is called once per frame
    void Update()
    {
        if(isDie)
        {
            return;
        }
        info = ani.GetCurrentAnimatorStateInfo(0);
        if(info.IsName("Attack"))
        {
            return;
        }
        Move();
        Attack();
        
    }
    private void Move()
    {
       

        if (JudgeMove(transform.position))
        {
            float input = Input.GetAxis("Horizontal");
            if (input < 0 && dir == E_Direction.Right)
            {
                dir = E_Direction.Left;
                transform.Rotate(new Vector3(0, 180, 0));
            }
            if (input > 0 && dir == E_Direction.Left)
            {
                dir = E_Direction.Right;
                transform.Rotate(new Vector3(0, 180, 0));
            }
            if (dir == E_Direction.Left)
                transform.Translate(new Vector3(input * movespeed * Time.deltaTime, 0, 0));
            else
                transform.Translate(new Vector3(-input * movespeed * Time.deltaTime, 0, 0));
        }
        else
        {
            if (transform.position.x < -40)
                transform.position = new Vector3(39.9f, transform.position.y, transform.position.z);
            if(transform.position.x>40)
                transform.position = new Vector3(-39.9f, transform.position.y, transform.position.z);
        }


        Jump();
    }
    private void Jump()
    {
        
        if (Input.GetKeyDown(KeyCode.Space) && isGround && !isJump)
        {
            
            isJump = true;
            GetComponent<Rigidbody2D>().AddForce(Vector3.up * Jspeed);
            Jumpcount--;
            m_jump = false;
        }

        Jump2();

    }
    private void Jump2()
    {
        if (isJump)
        {
            if (!m_jump)
            {
                if (Input.GetKeyDown(KeyCode.W) && (Jumpcount > 0))
                {
                    isJump = true;
                    GetComponent<Rigidbody2D>().AddForce(Vector3.up * Jspeed2);
                    Jumpcount--;

                }
            }

        }

    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Road")

        {
            isJump = false;
            isGround = true;
            Jumpcount = 2;
        }
        if(collision.gameObject.tag=="Enemy")
        {
            ani.SetTrigger("Die");
            isDie = true;
        }
    }
    private void Attack()
    {
        if(Input.GetMouseButtonDown(0))
        {
            ani.SetTrigger("Attack");
            JudgeTargetEnemy();
        }
    }
    //-32~32
    private bool JudgeMove(Vector3 ps)
    {
        if(ps.x>-40&&ps.x<40)
        {
            return true;
        }
        return false; 
    }
    private void JudgeTargetEnemy()
    {
        List<GameObject> listEnemys = enemyMgr.ListAllEnemy;
        for (int i = 0; i < listEnemys.Count; i++)
        {
            float distance = Vector3.Distance(transform.position, new Vector3(listEnemys[i].transform.position.x, transform.position.y, listEnemys[i].transform.position.z));
            if(distance<=10)
            {
                Vector3 v = Vector3.Cross(transform.position, listEnemys[i].transform.position);
                if((v.z<0&&dir==E_Direction.Left)||(v.z>0&&dir==E_Direction.Right))
                {
                    GameObject targetEnemy = listEnemys[i];
                    enemyMgr.RemoveEnemy(targetEnemy);
                    Destroy(targetEnemy);
                }
            }
        }
    }

}
