using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckPoint : MonoBehaviour
{
    public bool isPassed { private set; get; }

    void Start()
    {
        isPassed = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.CompareTag("Player"))
            isPassed = true;
    }
    
    public void ResetCheckPoint()
    {
        if (isPassed)
            isPassed = false;
    }
}
