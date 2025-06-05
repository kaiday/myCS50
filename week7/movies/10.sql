SELECT "name" FROM "people"
WHERE "id" IN (SELECT "directors"."person_id" FROM "movies"
                JOIN "directors" ON "directors"."movie_id" = "movies"."id"
                JOIN "ratings" ON "ratings"."movie_id" = "movies"."id"
                WHERE "ratings"."rating" >= 9.0);
