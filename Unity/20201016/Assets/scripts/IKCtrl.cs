using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IKCtrl : MonoBehaviour
{
    //反向动力学    通过子物体去带动父物体的运动    
    public Transform apple;
    private Animator ani;
    public bool isOpen = false;//开关，默认为关闭
    // Start is called before the first frame update
    void Start()
    {
        ani = this.GetComponent<Animator>();
    }
    private void OnAnimatorIK(int layerIndex)
    {
        if(ani!=null)
        {
            if(isOpen)
            {
                ani.SetIKPositionWeight(AvatarIKGoal.LeftHand, 1f);
                ani.SetIKRotationWeight(AvatarIKGoal.LeftHand, 1f);
                if(apple!=null)
                {
                    ani.SetIKPosition(AvatarIKGoal.LeftHand, apple.position);
                    ani.SetIKRotation(AvatarIKGoal.LeftHand, apple.rotation);
                }
            }
            else
            {
                ani.SetIKPositionWeight(AvatarIKGoal.LeftHand, 0f);
                ani.SetIKRotationWeight(AvatarIKGoal.LeftHand, 0f);
            }
            //头部的IK
            if(isOpen)
            {
                ani.SetLookAtWeight(1f);
                {
                    if(apple!=null)
                    {
                        ani.SetLookAtPosition(apple.position);
                    }
                }
            }
        }
    }
}
