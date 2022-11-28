using System.Collections;
using System.Collections.Generic;
using UnityEngine;

enum SIGNAL_COLOR
{
    YELLOW = 0,
    RED = 1,
    GREEN = 2,
}

public class SignalLight : MonoBehaviour
{
    [SerializeField]
    private Renderer signal;
    private int signalCount;
    // Start is called before the first frame update
    void Start()
    {
        signalCount = signal.materials.Length;
        for (int i = 0; i < signalCount; i++)
            signal.materials[i].color = Color.black;
    }

    public void ChangeLightColor(int signalColorNumber)
    {
        switch ((SIGNAL_COLOR)signalColorNumber)
        {
            case SIGNAL_COLOR.YELLOW:
                ChangeColor(Color.yellow, signalColorNumber);
                break;
            case SIGNAL_COLOR.RED:
                ChangeColor(Color.red, signalColorNumber);
                break;
            case SIGNAL_COLOR.GREEN:
                ChangeColor(Color.green, signalColorNumber);
                break;
        }
    }

    void ChangeColor(Color changeColor, int colorNumber)
    {
        for (int i = 0; i < signalCount; i++)
        {
            if (i == colorNumber)
                signal.materials[i].color = changeColor;
            else
                signal.materials[i].color = Color.black;
        }
    }
}
