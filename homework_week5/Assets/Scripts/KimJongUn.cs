using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class KimJongUn : MonoBehaviour {

	//allow the script to have a prefab associated with it 
	public GameObject myPrefab;


	// Use this for initialization
	void Start () {
		MySphere.globalSpeed = 10.0f;
		MySphere.globalTarget = gameObject;
		MySphere.globalYawing = 30.0f;

		StartCoroutine (CreateSpheres());
	}

	IEnumerator CreateSpheres() {
		
		for (int i = 0; i < 80; i++) {
			Vector3 pos = new Vector3 (Random.Range (-5, 5), Random.Range (-5, 5), Random.Range (-5, 5));

			GameObject newObject = Instantiate (myPrefab);
			//instantiate means create a new copy of an object and put it in a scene (dynamic creation of objects)
			newObject.transform.position = pos;

//			Debug.Log (newObject.GetComponent<MySphere> ().globalSpeed);

			//wait some amount of seconds to continue 
			yield return new WaitForSeconds(0.5f);
		}
	}

	// Update is called once per frame
	void Update () {
		
	}
}
