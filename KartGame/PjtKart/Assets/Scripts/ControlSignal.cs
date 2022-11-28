using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControlSignal : MonoBehaviour
{
    [SerializeField]
    private SignalLight[] signalArray;
    [SerializeField]
    private AudioClip startClip;
    private AudioSource audioSource;

    private void Awake()
    {
        audioSource = GetComponent<AudioSource>();
    }
    public void ControlSignalLight(int signalColorNumber)
    {
        for(int i = 0; i < signalArray.Length; i++)
        {
            signalArray[i].ChangeLightColor(signalColorNumber);
            audioSource.PlayOneShot(startClip);
        }
    }
}
