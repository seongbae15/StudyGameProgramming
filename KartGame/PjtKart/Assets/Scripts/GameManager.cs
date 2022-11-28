using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager instance;
    public bool isGameStart { private set; get; }
    private bool isGameEnd = false;
    private int countdownTime = 5;
    private int curLap = 1;
    private const int maxLap = 2;
    private float curLapTime;
    private float bestLapTime;

    [SerializeField]
    KartMovement playerMovement;
    private void Awake()
    {
        if(null==instance)
        {
            instance = this;
            return;
        }
        Destroy(gameObject);
    }


    // Start is called before the first frame update
    void Start()
    {
        Init();
    }
    public void Init()
    {
        isGameStart = false;
        isGameEnd = false;
        
        countdownTime = 5;
        curLap = 1;
        curLapTime = 0f;
        bestLapTime = 0f;

        playerMovement.Init();
        UIManager.instance.Init(maxLap);

        StartCoroutine(StartCountDown());
    }

    IEnumerator StartCountDown()
    {
        while (countdownTime >= 0)
        {
            if(countdownTime == 0)
            {
                isGameStart = true;
                StartCoroutine(StartLapTime());
            }
            UIManager.instance.DisplayCountdown(countdownTime);
            countdownTime--;
            yield return new WaitForSeconds(1f);
        }
        UIManager.instance.EndUICountdown();
    }

    IEnumerator StartLapTime()
    {
        while (!isGameEnd)
        {
            UIManager.instance.DispCurLaptime(curLapTime);
            curLapTime += Time.deltaTime;
            yield return null;
        }
    }


    public void UpdateLap()
    {
        if(!isGameEnd)
        {
            UpdateBestLaptime();
            if (curLap < maxLap)
                UpdateLapCount();
            else
                FinishRace();
        }
    }
    void UpdateLapCount()
    {
        curLap++;
        UIManager.instance.UpdateLapText(curLap, maxLap);

    }
    void FinishRace()
    {
        isGameEnd = true;
        UIManager.instance.DisplayGameEndScreen(bestLapTime);
    }
    void UpdateBestLaptime()
    {
        if(curLap == 1 || curLapTime < bestLapTime)
        {
            bestLapTime = curLapTime;
            UIManager.instance.UpdateBestLapTimeUI(bestLapTime);
            UIManager.instance.DispCurLaptime(curLapTime);
        }
        curLapTime = 0f;
    }

}
