SELECT AVG(rating)
FROM movies
JOIN ratings on movies.id=ratings.movie_id;