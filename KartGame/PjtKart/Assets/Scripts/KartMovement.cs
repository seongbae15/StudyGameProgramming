using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KartMovement : MonoBehaviour
{
    private PlayerController controller;
    private Rigidbody playerRb;

    //new
    private const float minKeyInput = 0.01f;
    private const float coefAcceleration = 6.94f;
    private const float speedLimit = 10f;
    private const float maxSteerAngle = 30;
    private const float coefMaxAccCurve = 2.0f;
    private const float coefMinAccCurve = 1.0f;
    private const float coefMaxSteerCurve = 1.0f;
    private const float coefMinSteerCurve = 0.5f;
    private const float wheelBase = 1.3f;
    public Vector3 initPosition { private set; get; }
    public Quaternion initRotation { private set; get; }
    public float maxSpeed { get { return speedLimit; } }

    public void Init()
    {
        controller = GetComponent<PlayerController>();
        playerRb = GetComponent<Rigidbody>();
        initPosition = new Vector3(0f, 0.52f, 0f);
        initRotation = Quaternion.Euler(new Vector3(0f, 0f, 0f));
        ResetPlayerPosition();
    }

    void FixedUpdate()
    {
        float inputAccel = controller.accInput;
        float inputSteering = controller.steeringInput;
        if(GameManager.instance.isGameStart)
            MoveKart(inputAccel, inputSteering);
    }

    void MoveKart(float inputAccel, float inputSteering)
    {
        Vector3 localVelocity = transform.InverseTransformVector(playerRb.velocity);
        float velocityRate = localVelocity.magnitude / speedLimit;
        float coefAccCurve = Mathf.Lerp(coefMaxAccCurve, coefMinAccCurve, velocityRate * velocityRate);
        float accApplied = coefAcceleration * coefAccCurve;
        if (localVelocity.magnitude >= speedLimit)
            accApplied = 0f;
        Vector3 appliedAccDir = transform.InverseTransformVector(transform.forward);
        Vector3 updatedLocalVelocity = localVelocity + inputAccel * appliedAccDir * accApplied * Time.deltaTime;
        if (Mathf.Abs(inputAccel) < minKeyInput)
            updatedLocalVelocity = Vector3.MoveTowards(updatedLocalVelocity, new Vector3(0f, updatedLocalVelocity.y, 0f), 0.5f);
        float coefYawRateCurve = Mathf.Lerp(coefMaxSteerCurve, coefMinSteerCurve, inputSteering* inputSteering);        
        float appliedYawRateDeg = updatedLocalVelocity.z / wheelBase * maxSteerAngle * inputSteering* coefYawRateCurve;
        Quaternion appliedDirection = Quaternion.AngleAxis(appliedYawRateDeg * Time.deltaTime, transform.InverseTransformVector(transform.up));
        if (Mathf.Abs(inputSteering) < minKeyInput)
            updatedLocalVelocity = Vector3.MoveTowards(updatedLocalVelocity, new Vector3(0f, updatedLocalVelocity.y, updatedLocalVelocity.z), 0.5f);

        playerRb.angularVelocity = new Vector3(0f, appliedYawRateDeg * Mathf.Deg2Rad, 0f);
        playerRb.velocity = transform.TransformVector(appliedDirection * updatedLocalVelocity);
    }

    public void ResetPlayerPosition()
    {
        transform.position = initPosition;
        transform.rotation = initRotation;
    }

}