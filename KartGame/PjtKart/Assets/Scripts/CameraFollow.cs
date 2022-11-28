using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    [SerializeField]
    private Transform targetTransform;

    void LateUpdate()
    {
        transform.position = targetTransform.position;
        transform.rotation = targetTransform.rotation;
    }
}
