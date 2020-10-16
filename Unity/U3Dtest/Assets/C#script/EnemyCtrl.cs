using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEditor;
using UnityEngine;
using UnityEngine.AI;

public class EnemyCtrl : MonoBehaviour
{
    
    private NavMeshAgent nav;
    //敌人的寻路目标
    private GameObject tank;
   // private GameObject tankeffectprefab;
    // Start is called before the first frame update
    void Start()
    {
       // tankeffectprefab = Resources.Load<GameObject>("Effect");
        nav = this.gameObject.GetComponent<NavMeshAgent>();
        tank = GameObject.Find("Tank");
    }

    // Update is called once per frame
    void Update()
    {
        //让敌人跟随坦克
        if(tank!=null)
        nav.SetDestination(tank.transform.position);
    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.name == "Tank")
        {
            Tool.Instance.InsObj("Effect", collision.transform.position, Quaternion.identity);
            Destroy(collision.gameObject);
        }
    }
}
