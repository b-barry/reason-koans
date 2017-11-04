open Helpers;

type nucleotide =
  | A
  | C
  | G
  | T;

type dna =
  | Base(nucleotide)
  | Strand(list(nucleotide));

let koans = (_) =>
  Mocha.describe("UnionTypes") @@
  (
    (_) => {
      Mocha.it("simple types are similar to enums in other languages") @@
      ((_) => todo() |> Mocha.eq(C));
      Mocha.it("more complex types can be built with a 'tag' and additional data") @@
      ((_) => Base(todo()) |> Mocha.eq(Base(C)));
      Mocha.it("switch statements may be used to extract the data from the type") @@
      (
        switch (Base(A)) {
        | Strand(nucleotides) => ((_) => [todo()] |> Mocha.eq(nucleotides))
        | Base(nucleotide) => ((_) => todo() |> Mocha.eq(nucleotide))
        }
      )
    }
  );
