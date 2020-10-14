using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameCtrl : MonoBehaviour
{
    private Button btn_Change;
    //用List链表来存放多种子弹
    GameObject bullet;
    GameObject Bigbullet;
    private GameObject currentBullet;
    // Start is called before the first frame update
    void Start()
    {
        btn_Change = GameObject.Find("Canvas/Btn_Change").GetComponent<Button>();
        btn_Change.onClick.AddListener(ChangeBullet);
        bullet = Resources.Load<GameObject>("Bullet");
        Bigbullet = Resources.Load<GameObject>("BigBullet");
        currentBullet = bullet;
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
        
    }
}
