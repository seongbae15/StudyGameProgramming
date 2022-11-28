using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DriverAnimation : MonoBehaviour
{
    private PlayerController playerController;
    [SerializeField]
    private Animator animator;
    private float curSteerAniValue;
    private const float motionSpeed = 10f;

    // Start is called before the first frame update
    void Start()
    {
        playerController = GetComponent<PlayerController>();
        curSteerAniValue = 0f;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        curSteerAniValue = Mathf.MoveTowards(curSteerAniValue, playerController.steeringInput, Time.deltaTime * motionSpeed);
        animator.SetFloat("Steering", curSteerAniValue);
    }
}
