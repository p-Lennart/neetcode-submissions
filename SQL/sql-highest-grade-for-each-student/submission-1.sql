WITH _numbered as (
    SELECT 
        student_id,
        exam_id,
        score,
        ROW_NUMBER() OVER (PARTITION BY student_id ORDER BY score DESC, exam_id ASC) AS row_num,
        DENSE_RANK() OVER (PARTITION BY student_id ORDER BY score DESC, exam_id ASC) AS dense_rnk
    FROM exam_results
)
SELECT student_id, exam_id, score
FROM _numbered
WHERE row_num = 1;