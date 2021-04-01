SELECT DISTINCT people.name
FROM people
INNER JOIN stars ON people.id = stars.person_id
INNER JOIN movies on stars.movie_id = movies.id
WHERE people.name NOT LIKE "Kevin Bacon" AND movies.title IN(
    SELECT movies.title
    FROM movies
    INNER JOIN stars ON movies.id = stars.movie_id
    INNER JOIN people on stars.person_id = people.id
    WHERE people.name LIKE "Kevin Bacon" AND people.birth = 1958
);