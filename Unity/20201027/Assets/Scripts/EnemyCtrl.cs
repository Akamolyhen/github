using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyCtrl : MonoBehaviour
{
    private bool isStartmove = false;
    private E_Direction dirdefault = E_Direction.Right;
    private float EnemySpeed = 5f;
    // Start is called before the first frame update
    void Start()
    {
        //给怪物随机移动的方向
        int num = Random.Range(0, 2);
        dirdefault = (E_Direction)num;
    }

    // Update is called once per frame
    void Update()
    {
        if (isStartmove)
        {
            if (dirdefault == E_Direction.Left)
            {
                transform.Rotate(0, 180, 0);
                dirdefault = E_Direction.Right;
                transform.Translate(new Vector3(EnemySpeed * Time.deltaTime, 0, 0));
            }
            else
            {
                transform.Translate(new Vector3(EnemySpeed * Time.deltaTime, 0, 0));
            }
        }
    }
    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Road")
        
            isStartmove = true;
        }
    }
    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.name == "Road")
        {
            GameObject.Find("EnemyManager").GetComponent<EnemyManager>().RemoveEnemy(this.gameObject);
            Destroy(this.gameObject);
        }
    }
}
