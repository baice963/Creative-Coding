using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeMoves : MonoBehaviour {

	//data types for variables
	public float rotationSpeed = .6f;


	//called before Start 
	//initialize the values of game objects here
	void Awake(){
		
	}

	// Make connections to other game objects
	void Start () {
		
		
	}

	// Update is called once per frame
	void Update () {

		//transform always controls the objects position, rotaiton and all that jazz
		//deltaTime is useful in making my animations in real time not the frameRate 

		Vector3 rotation = new Vector3 (0.0f, Time.deltaTime * rotationSpeed, 0.0f);
			transform.Rotate(rotation);

		//copied the current position 
		Vector3 pos = transform.position;

		//alter the y
		pos.x = Mathf.Sin (Time.time * 4.0f)* 4.0f;
		pos.y = Mathf.Sin (Time.time * 1.0f)* 4.0f;

		//copy the altered position back into the transform
		transform.position = pos;


	}

	//called after all other updates
	void LateUpdate(){
		
	}

}
