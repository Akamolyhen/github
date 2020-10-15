using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameCtrl : MonoBehaviour
{
    float time = 0;
    private Button btn_Change;
    //用List链表来存放多种子弹
    GameObject bullet;
    GameObject Bigbullet;
    private GameObject currentBullet;
    private GameObject enemyPrefab;
    //敌人生成点
    private GameObject[] arrMaker;
    public int currentCount = 0;
    // Start is called before the first frame update
    void Start()
    {
        btn_Change = GameObject.Find("Canvas/Btn_Change").GetComponent<Button>();
        btn_Change.onClick.AddListener(ChangeBullet);
        bullet = Resources.Load<GameObject>("Bullet");
        Bigbullet = Resources.Load<GameObject>("BigBullet");
        enemyPrefab = Resources.Load<GameObject>("Enemy");
        currentBullet = bullet;
        arrMaker = GameObject.FindGameObjectsWithTag("EnemyMake");
    }
    private void ChangeBullet()
    {
        if(currentBullet.name=="Bullet")
        {
            currentBullet = Bigbullet;
        }
        else
        {
            currentBullet = bullet;
        }
    }
    public GameObject GetBullet()
    {
        return currentBullet;
    }
    // Update is called once per frame
    void Update()
    {
        time += Time.deltaTime;
        if(time>=3)
        {
            MakeEnemy();
            time = 0;
        }
    }
    private void MakeEnemy()
    {
        if (currentCount <6)
        {
            System.Random rd = new System.Random();
            int num = rd.Next(0, arrMaker.Length);//产生一个0～2的随机数
            Instantiate(enemyPrefab, arrMaker[num].transform.position, Quaternion.identity);
            currentCount++;
        }
        
    }
    public void MinusEnemyCount()
    {
        currentCount--;
    }
}
