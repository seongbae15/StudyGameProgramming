using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KartAudio : MonoBehaviour
{
    [SerializeField]
    AudioSource startSound;
    [SerializeField]
    AudioSource idleSound;
    [SerializeField]
    AudioSource runningSound;

    [SerializeField]
    Rigidbody playerRb;
    [SerializeField]
    KartMovement kartMovement;


    // Start is called before the first frame update
    void Start()
    {
        idleSound.volume = 0;
        runningSound.volume = 0;
    }

    // Update is called once per frame
    void Update()
    {
        float soundRate = playerRb.velocity.magnitude / kartMovement.maxSpeed;
        idleSound.volume = 1-soundRate;
        runningSound.volume = soundRate;
    }
}
