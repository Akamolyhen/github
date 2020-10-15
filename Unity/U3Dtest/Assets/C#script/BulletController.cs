using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletController : MonoBehaviour
{
    private float speed = 100;
   
    //private static int count1 = 0;
    //private static int count2 = 0;
    // Start is called before the first frame update
    //爆炸特效的预制体
    private GameObject effectPrefab;
    private GameCtrl gameCtrl;
    void Start()
    {
        effectPrefab = Resources.Load<GameObject>("Effect");
        gameCtrl = GameObject.Find("GameCtrl").GetComponent<GameCtrl>();
        Destroy(this.gameObject,2f);
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.Translate(Vector3.forward*speed*Time.deltaTime);
    }
    private void OnCollisionEnter(Collision collision)
    {
        
        if(collision.gameObject.tag=="Enemy")
        {

            gameCtrl.MinusEnemyCount();
            Destroy(this.gameObject);
            
                //播放爆炸特效
            Tool.InstantiateObj("Effect", collision.transform.position, Quaternion.identity);
                Destroy(collision.gameObject);
                Destroy(this.gameObject);
                
            
            
        }
        
    }

}
