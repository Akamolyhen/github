
using UnityEngine;

public class HeroCtrl : MonoBehaviour
{
    Animator ani;
    private float movespeed = 1000f;
    private float Jspeed = 100000f; private float Jspeed2 = 150000f;
    private bool isJump = false;
    private bool isGround = false;
    private bool m_jump = true;
    
    private int Jumpcount=2 ;
    
    private enum E_Direction
    {
        Left,
        Right
    }
    // Start is called before the first frame update
    void Start()
    {
        ani = GetComponent<Animator>();
    }
    E_Direction dir = E_Direction.Left;
    // Update is called once per frame
    void Update()
    {
        Move();
        Attack();
        
        
    }
    private void OnCollisionEnter(Collision collision)
    {
        //Debug.Log(collision.gameObject.name);
        if (collision.gameObject.name == "Ground")

        {
            isJump = false;
            isGround = true;
            Jumpcount = 2;
        }
    }
    private void Move()
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
        Jump();
    }
    private void Attack()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ani.SetTrigger("Attack");
        }
    }
    private void Jump()
    {
        
        if(Input.GetKeyDown(KeyCode.Space)&&isGround&&!isJump)
        {
            isJump = true;
            GetComponent<Rigidbody>().AddForce(Vector3.up * Jspeed);
            Jumpcount--;
            m_jump = false;
        }
     
        Jump2();
       
    }
    private void Jump2()
    {
        if(isJump)
        {
            if(!m_jump)
            {
                if (Input.GetKeyDown(KeyCode.W) && (Jumpcount > 0))
                {
                    isJump = true;
                    GetComponent<Rigidbody>().AddForce(Vector3.up * Jspeed2);
                    Jumpcount--;

                }
            }
          
        }
    }
   
}
