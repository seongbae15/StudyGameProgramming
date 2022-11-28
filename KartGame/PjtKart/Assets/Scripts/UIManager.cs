using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
#if UNITY_EDITOR
using UnityEditor;
#endif


struct DispTime
{
    public int dispMinute;
    public int dispSecond;
    public int dispMilisecond;
}

public class UIManager : MonoBehaviour
{
    public static UIManager instance { get; private set; }
    [SerializeField]
    private Rigidbody playerRb;
    [SerializeField]
    TextMeshProUGUI speedText;
    [SerializeField]
    TextMeshProUGUI countText;
    [SerializeField]
    TextMeshProUGUI timerText;
    [SerializeField]
    TextMeshProUGUI bestTimeText;
    [SerializeField]
    ControlSignal controlSignal;
    [SerializeField]
    TextMeshProUGUI lapText;
    [SerializeField]
    GameObject endScreen;
    [SerializeField]
    TextMeshProUGUI recordText;

    private void Awake()
    {
        if(null == instance)
        {
            instance = this;
            return;
        }
        Destroy(gameObject);
    }

    public void Init(int maxLap)
    {
        UpdateLapText(1, maxLap);
        UpdateBestLapTimeUI(0f);
        DispCurLaptime(0f);
        controlSignal.gameObject.SetActive(true);
        countText.gameObject.SetActive(true);

    }

    public void DisplayCountdown(int countTime)
    {
        switch (countTime)
        {
            case 5:
            case 4:
                controlSignal.ControlSignalLight((int)SIGNAL_COLOR.RED);
                countText.color = Color.red;
                countText.text = string.Format("{0}", countTime);
                break;
            case 3:
            case 2:
            case 1:
                controlSignal.ControlSignalLight((int)SIGNAL_COLOR.YELLOW);
                countText.color = Color.yellow;
                countText.text = string.Format("{0}", countTime);
                break;
            case 0:
                controlSignal.ControlSignalLight((int)SIGNAL_COLOR.GREEN);
                countText.color = Color.green;
                countText.text = "Start";
                break;
        }
    }

    public void EndUICountdown()
    {
        controlSignal.gameObject.SetActive(false);
        countText.gameObject.SetActive(false);
    }
    DispTime CalculateTime(float lapTime)
    {
        DispTime tempTime;
        tempTime.dispSecond = (int)lapTime;
        tempTime.dispMilisecond = (int)((lapTime - tempTime.dispSecond) * 100);
        tempTime.dispMinute = (int)(lapTime / 60);
        if (tempTime.dispSecond >= 60)
            tempTime.dispSecond -= 60 * tempTime.dispMinute;
        return tempTime;
    }

    public void DispCurLaptime(float curLapTime)
    {
        DispTime dispTime = CalculateTime(curLapTime);
        timerText.text = string.Format("Lap Time {0}:{1}:{2}", dispTime.dispMinute.ToString("D2"), dispTime.dispSecond.ToString("D2"), dispTime.dispMilisecond.ToString("D2"));
    }

    void FixedUpdate()
    {
        UpdateSpeedometer();
    }

    void UpdateSpeedometer()
    {
        int dispSpeed = (int)(playerRb.velocity.magnitude * 3.6f);
        speedText.text = string.Format("{0} km/h", dispSpeed);
    }

    public void UpdateLapText(int curLap,int maxLap)
    {
        lapText.text = string.Format("Lap : {0}/{1}", curLap, maxLap);
    }

    public void UpdateBestLapTimeUI(float bestLaptime)
    {
        DispTime dispTime = CalculateTime(bestLaptime);
        bestTimeText.text = string.Format("Best Time {0}:{1}:{2}", dispTime.dispMinute.ToString("D2"), dispTime.dispSecond.ToString("D2"), dispTime.dispMilisecond.ToString("D2"));
    }
    public void DisplayGameEndScreen(float bestLaptime)
    {
        endScreen.SetActive(true);
        DispTime dispTime = CalculateTime(bestLaptime);
        recordText.text = string.Format("Your Best Lap Time\n{0}:{1}:{2}", dispTime.dispMinute.ToString("D2"), dispTime.dispSecond.ToString("D2"), dispTime.dispMilisecond.ToString("D2"));
    }

    public void ExitGame()
    {
#if UNITY_EDITOR
        EditorApplication.ExitPlaymode();
#else
        Application.Quit();
#endif
        Application.Quit();

    }

    public void RestartGame()
    {
        endScreen.SetActive(false);

        GameManager.instance.Init();
    }

}
