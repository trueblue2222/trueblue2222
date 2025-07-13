using UnityEngine;

public class MovingObject : MonoBehaviour
{

    public float speed = 0.1f;
    private Vector3 vector;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // 상하좌우 방향키가 눌렸을 경우
        if(Input.GetAxisRaw("Horizontal") != 0 || Input.GetAxisRaw("Vertical") != 0)
        {
            // 벡터값 설정(x, y는 받아오고 z는 그냥 그대로)
            vector.Set(Input.GetAxisRaw("Horizontal"), Input.GetAxisRaw("Vertical"), transform.position.z);

            if(vector.x != 0)
            {   // vector.x 값은 좌 방향키(-1) 혹은 우 방향키(1)이 리턴되므로 speed 만큼 곱해서 이동
                transform.Translate(vector.x * speed, 0, 0);
            }

            else if(vector.y != 0)
            {
                transform.Translate(0, vector.y * speed, 0);
            }
        }
    }
}
