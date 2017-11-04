open Helpers;

open Containers;

module ISet =
  Set.Make(
    {
      type t = int;
      let compare = compare;
    }
  );

let koans = (_) =>
  Mocha.describe("Sets") @@
  (
    (_) => {
      Mocha.it("Set.Make is a module functor that takes an OrderedType") @@
      (
        (_) => {
          module StringSet = Set.Make(String);
          Mocha.ok(true)
        }
      );
      Mocha.it("Set.Make takes any module with { type: t, compare: t => t => int }") @@
      (
        (_) => {
          module FloatSet = Set.Make(Float);
          Mocha.ok(true)
        }
      );
      Mocha.it("Set.Make can take any module that obeys that interface") @@
      (
        (_) => {
          module IntSet =
            Set.Make(
              {
                type t = int;
                let compare = compare;
              }
            );
          Mocha.ok(true)
        }
      );
      Mocha.it("can be created empty") @@ ((_) => todo() |> ISet.equal(ISet.empty) |> Mocha.ok);
      Mocha.it("can be created from a list") @@
      ((_) => ISet.of_list(todo()) |> ISet.equal(ISet.add(1, ISet.empty)) |> Mocha.ok);
      Mocha.it("can be created of one element") @@
      ((_) => ISet.singleton(todo()) |> ISet.equal(ISet.of_list([1])) |> Mocha.ok);
      Mocha.it("will not add duplicate elements") @@
      (
        (_) =>
          ISet.of_list(todo()) |> ISet.equal(ISet.of_list([1, 1, 2, 3, 4, 4, 5, 1, 2])) |> Mocha.ok
      );
      Mocha.it("you can add elements to a set") @@
      ((_) => ISet.empty |> ISet.add(todo()) |> ISet.equal(ISet.of_list([1])) |> Mocha.ok);
      Mocha.it("but duplicates will not be added") @@
      (
        (_) =>
          ISet.of_list([1, 2, 3])
          |> ISet.add(todo())
          |> ISet.equal(ISet.of_list([1, 2, 3]))
          |> Mocha.ok
      );
      Mocha.it("remove may subtract an element from a set") @@
      (
        (_) =>
          ISet.of_list([1, 2, 3])
          |> ISet.remove(todo())
          |> ISet.equal(ISet.of_list([1, 2]))
          |> Mocha.ok
      );
      Mocha.it("remove is a no op if the element isn't in the set") @@
      (
        (_) =>
          ISet.of_list([1, 2, 3])
          |> ISet.remove(todo())
          |> ISet.equal(ISet.of_list([1, 2, 3]))
          |> Mocha.ok
      );
      Mocha.it("member can check if an element is in a set") @@
      ((_) => ISet.of_list([1, 2, 3]) |> ISet.mem(todo()) |> Mocha.ok)
    }
  );
