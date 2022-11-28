using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KartAnimation : MonoBehaviour
{
    private PlayerController controller;
    private Rigidbody playerRb;

    [SerializeField]
    private List<CapsuleCollider> wheelCapsuleColliders;
    [SerializeField]
    private List<GameObject> drivingWheels;
    [SerializeField]
    private List<GameObject> steerWheels;

    private const float maxSteerAngleDeg = 30f;
    private const float coefSteerDelta = 360f;

    private float frontWheelRadius;
    private float rearWheelRadius;
    private float steerDirCoef;

    void Start()
    {
        controller = GetComponent<PlayerController>();
        playerRb = GetComponent<Rigidbody>();
        frontWheelRadius = wheelCapsuleColliders[0].radius;
        rearWheelRadius = wheelCapsuleColliders[1].radius;
        steerDirCoef = 1f;
    }

    void FixedUpdate()
    {
        UpdateAniDriveTire();
        UpdateAniSteerTire();

    }

    void UpdateAniDriveTire()
    {
        Vector3 kartLocalVelocity = transform.InverseTransformVector(playerRb.velocity);
        float kartSpeed = kartLocalVelocity.magnitude;
        if (kartLocalVelocity.z < 0)
            steerDirCoef = -1f;
        else if (kartLocalVelocity.z > 0)
            steerDirCoef = 1f;
        for (int i = 0; i < drivingWheels.Count; i++)
        {
            switch (i)
            {
                case 0:
                case 1:
                    drivingWheels[i].transform.Rotate(new Vector3(kartSpeed / frontWheelRadius * steerDirCoef, 0f, 0f));
                    break;
                case 2:
                case 3:
                    drivingWheels[i].transform.Rotate(new Vector3(kartSpeed / rearWheelRadius * steerDirCoef, 0f, 0f));
                    break;
            }
        }

    }

    void UpdateAniSteerTire()
    {
        float steerAngleDeg = controller.steeringInput * maxSteerAngleDeg;
        for (int i = 0; i < steerWheels.Count; i++)
        {
            float curSteerAngleDeg = Mathf.MoveTowardsAngle(steerWheels[i].transform.localEulerAngles.y, steerAngleDeg, Time.deltaTime * coefSteerDelta);
            steerWheels[i].transform.localEulerAngles = new Vector3(0f, curSteerAngleDeg, 0f);
        }

    }
}
