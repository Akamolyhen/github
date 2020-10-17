 using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class PackPanel : MonoBehaviour
{
    private Button Btn_add;//增加的按钮
    private Button Btn_minus;
    private Button Btn_clear;
    private Button Btn_adds;
    //item的预制体
    private GameObject itemPrefab;
    //item的父物体
    private Transform content;
    //用于显示批量增加的数量
    private Text txt_count;
    //记录当前有多少个物体(隐藏的item数量)
    //private int Txt_count=0;
    private List<GameObject> list = new List<GameObject>();//对象缓存池
    // Start is called before the first frame update
    void Start()
    {
        content = this.transform.Find("Scroll View/Viewport/Content");
        Btn_add = this.transform.Find("Btn_add").GetComponent<Button>();
        Btn_minus = this.transform.Find("Btn_minus").GetComponent<Button>();
        Btn_clear = this.transform.Find("Btn_clear").GetComponent<Button>();
        Btn_adds = this.transform.Find("Btn_adds").GetComponent<Button>();
        txt_count = this.transform.Find("InputField/Txt_count").GetComponent<Text>();
        Btn_add.onClick.AddListener(AddItem);
        Btn_minus.onClick.AddListener(MinusItem);
        Btn_clear.onClick.AddListener(Clear);
        Btn_adds.onClick.AddListener(Addmany);
        itemPrefab = Resources.Load<GameObject>("Image");

    }
    private void AddItem()
    {
        if(list.Count==0)
        {
            GameObject item = Instantiate(itemPrefab);
            item.transform.SetParent(content, false);
        }
        else
        {
            //for(int i=0;i<content.childCount;i++)
            //{
            //    if(!content.GetChild(i).gameObject.activeInHierarchy)
            //    {
            //        content.GetChild(i).gameObject.SetActive(true);
            //        Txt_count--;
            //        break;
            //    }
            //}//通过循环去获得被隐藏的物体
            list[0].SetActive(true);
            list.Remove(list[0]);

        }
        
    }
    private void MinusItem()
    {
        if(content.childCount!=0)
        {
            for(int i=0;i<content.childCount;i++)
            {
                GameObject go = content.GetChild(i).gameObject;
                if(go.activeInHierarchy)
                {
                    go.SetActive(false);
                    //Txt_count++;
                    list.Add(go);
                    break;
                }
            }
        }
        //Destroy(content.GetChild(0).gameObject);//因为销毁后之后若再利用，会浪费资源，所以先隐藏

    }
    private void Clear()
    {
        #region 旧方法
        //if(content.childCount!=0)
        //{
        //    for(int i=0;i<content.childCount;i++)
        //    {
        //        GameObject go = content.GetChild(i).gameObject;
        //        Destroy(go);
        //    }
        //}
        #endregion
        if (content.childCount != 0)
        {
            for (int i = 0; i < content.childCount; i++)
            {
                GameObject go = content.GetChild(i).gameObject;
                if (go.activeInHierarchy)
                {
                    go.SetActive(false);
                    //Txt_count++;
                    list.Add(go);
                }
            }
        }
    }
    private void Addmany()
    {
        int count = int.Parse(txt_count.text);
        for(int i=0;i<count;i++)
        {
            AddItem();
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
