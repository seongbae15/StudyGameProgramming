using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private string steeringAxis = "Horizontal";
    private string accAxis = "Vertical";
    private KeyCode driftKey = KeyCode.LeftShift;
    public float steeringInput { get; private set; }
    public float accInput { get; private set; }
    public bool driftInput { get; private set; }

    // Update is called once per frame
    void Update()
    {
        steeringInput = Input.GetAxis(steeringAxis);
        accInput = Input.GetAxis(accAxis);
        driftInput = Input.GetKey(driftKey);
    }
}
