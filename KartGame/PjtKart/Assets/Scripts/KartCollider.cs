using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KartCollider : MonoBehaviour
{
    private AudioSource collisionAudioSource;
    [SerializeField]
    AudioClip collsionClip;

    void Start()
    {
        collisionAudioSource = GetComponent<AudioSource>();

    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.CompareTag("Wall"))
            collisionAudioSource.PlayOneShot(collsionClip);
    }
}
