using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckPointManager : MonoBehaviour
{
    [SerializeField]
    private List<CheckPoint> checkPoints;
    public bool isAllPassed { private set; get; }

    void Start()
    {
        isAllPassed = false;
    }

    public bool CheckAllCheckPointsPassed()
    {
        for(int i=0;i< checkPoints.Count; i++)
        {
            if (!checkPoints[i].isPassed)
            {
                isAllPassed = false;
                return isAllPassed;
            }
        }
        isAllPassed = true;
        return isAllPassed;
    }

    public void ResetAllCheckPoint()
    {
        for(int i = 0; i < checkPoints.Count; i++)
            checkPoints[i].ResetCheckPoint();
        isAllPassed = false;
    }
}
