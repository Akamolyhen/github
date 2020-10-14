using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletController : MonoBehaviour
{
    private float speed = 100;
    private static int count = 0;
    private static int count1 = 0;
    private static int count2 = 0;
    // Start is called before the first frame update
    //爆炸特效的预制体
    private GameObject effectPrefab;
    void Start()
    {
        effectPrefab = Resources.Load<GameObject>("Effect");
        Destroy(this.gameObject,2f);
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.Translate(Vector3.forward*speed*Time.deltaTime);
    }
    private void OnCollisionEnter(Collision collision)
    {
        
        if(collision.gameObject.name=="Enemy")
        {
            count++;
            Destroy(this.gameObject);
            if (count==5)
            {
                //播放爆炸特效
                Instantiate(effectPrefab, collision.transform.position, Quaternion.identity);
                Destroy(collision.gameObject);
                Destroy(this.gameObject);
            }
            
        }
        if (collision.gameObject.name == "Enemy1")
        {
            count1++;
            Destroy(this.gameObject);
            if (count1 == 5)
            {
                Instantiate(effectPrefab, collision.transform.position, Quaternion.identity);
                Destroy(collision.gameObject);
                Destroy(this.gameObject);
            }

        }
        if (collision.gameObject.name == "Enemy2")
        {
            count2++;
            Destroy(this.gameObject);
            if (count2 == 5)
            {
                Instantiate(effectPrefab, collision.transform.position, Quaternion.identity);
                Destroy(collision.gameObject);
                Destroy(this.gameObject);
            }

        }
    }

}
