using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Mainpanel : MonoBehaviour
{
    private Button btn_Change;
    private Image img_logo;
    // Start is called before the first frame update
    
    void Start()
    {
        btn_Change =this.transform.Find("Btn_Change").GetComponent<Button>();
        img_logo = this.transform.Find("Img_Logo").GetComponent<Image>();
        btn_Change.onClick.AddListener(ChangeImg);
    }
    private void ChangeImg()
    {
        img_logo.sprite = Resources.Load<Sprite>("new_logo");
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
