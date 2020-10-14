using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class TankContrlloer : MonoBehaviour
{
    // Start is called before the first frame update
    private float speed = 10;
    private float rotaterate = 100;
    //子弹的预制体
    private GameObject bulletPrefab;
    //子弹的生成位置
    // private Vector3 startPs;
    private GameObject startPsObj;
    private GameCtrl gameCtrl;
    void Start()
    {
        //去Resources 文件夹里面动态加载子弹
        //bulletPrefab = Resources.Load<GameObject>("Bullet");
        //因为设置成了私有化，通过代码来查找
        gameCtrl = GameObject.Find("GameCtrl").GetComponent<GameCtrl>();
        
        startPsObj = this.transform.Find("Paoguan/StartPs").gameObject;
    }

    // Update is called once per frame
    void Update()
    {
        bulletPrefab = gameCtrl.GetBullet();
        float v = Input.GetAxis("Vertical");//获取垂直方向的输入
        float h = Input.GetAxis("Horizontal");//获取水平方向的输入
        //Debug.Log("水平方向的输入是" + h);//取值范围是-1～1
        //Debug.Log("垂直方向的输入是" + v);//取值范围是-1～1
        Vector3 vertical = new Vector3(0,0,v*speed*Time.deltaTime);//Time.deltaTime把帧数率转换成秒速率
        this.transform.Translate(vertical);
        Vector3 rotate = new Vector3(0, h * rotaterate * Time.deltaTime, 0);
        this.transform.Rotate(rotate);
        if (Input.GetMouseButtonDown(0))//GetMouseButtonDown获取鼠标单击（0左键，1右键，2滚轮)
        {
            if(!EventSystem.current.IsPointerOverGameObject())//判断鼠标是否在UI元素上面
            Instantiate(bulletPrefab,startPsObj.transform.position,startPsObj.transform.rotation);
        }
    }
}
