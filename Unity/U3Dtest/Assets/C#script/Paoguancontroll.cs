using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class Paoguancontroll : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }
   

    // Update is called once per frame
    void Update()
    {

        if (Input.GetKey(KeyCode.Q) && transform.rotation.x <= 0)
        {
            
            this.transform.Rotate(Vector3.right  ,Space.Self);
        }
        if (Input.GetKey(KeyCode.E) &&  transform.rotation.x >= -0.3)
        {
            
            this.transform.Rotate(Vector3.right*(-1), Space.Self);
        }

    }
}
