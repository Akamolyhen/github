using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyManager : MonoBehaviour
{
    //生成怪物的速度
    private int makeCount = 1;
    private float time = 0f;
    //敌人的预制体
    private GameObject enmeyPrefab;
    //怪物生成点
    private Vector3 enemyStarPs;
    //生成怪物的左右两个边界标签
    private float x_target1, x_target2;
    // Start is called before the first frame update
    void Start()
    {
        enmeyPrefab = Resources.Load<GameObject>("Enemy");
        x_target1 = transform.Find("MakeEnemyTag/Tag1").transform.position.x;
        x_target2 = transform.Find("MakeEnemyTag/Tag2").transform.position.x;
    }

    // Update is called once per frame
    void Update()
    {
        time += Time.deltaTime;
        if (time >= 1)
        {
            //随机出一个怪物生成的X轴

            for (int i = 0; i < makeCount; i++)
            {
                float X = Random.Range(x_target1, x_target2);
                enemyStarPs = new Vector3(X, 24, 0);
                Instantiate(enmeyPrefab, enemyStarPs, Quaternion.identity);
            }
            time = 0;
        }
    }
}
