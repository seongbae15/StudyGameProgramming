using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FinishLine : MonoBehaviour
{
    [SerializeField]
    private CheckPointManager checkPointManager;

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            if (checkPointManager.CheckAllCheckPointsPassed())
            {
                GameManager.instance.UpdateLap();
                checkPointManager.ResetAllCheckPoint();
            }
        }
    }
}
