SELECT DISTINCT("title") FROM "movies"
WHERE "id" IN (SELECT "stars"."movie_id" FROM "stars"
                LEFT JOIN "people" ON "people"."id" = "stars"."person_id"
                WHERE "people"."name" = "Bradley Cooper" OR "people"."name" = "Jennifer Lawrence"
                GROUP BY "stars"."movie_id" HAVING COUNT("stars"."movie_id") = 2);