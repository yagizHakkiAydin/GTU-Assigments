using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarMoveController : MonoBehaviour
{


    bool moveLeft = false;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(this.transform);
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (transform.position[0] > 0.075f)
        {
            moveLeft = true;
        }
        else if(transform.position[0] < -0.075f)
        {
            moveLeft = false;
        }
        // Move the car based on the current direction
        if (moveLeft)
        {
            Vector3 newPosition = transform.position - new Vector3(0.001f, 0f, 0f);
            transform.position = newPosition;
        }
        else if(!moveLeft)
        {
            Vector3 newPosition = transform.position + new Vector3(0.001f, 0f, 0f);
            transform.position = newPosition;
        }


    }
}
