open Jest;
open Expect;

module type Koan = {let koans: unit => unit;};

let iterator = ((module M): (module Koan)) => M.koans();

describe("ReasonML bucklescript Koans", (_) =>
  List.iter(
    iterator,
    [
      (module Koan01_Expects)
    ]
  )
);
