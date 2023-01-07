<script>
  import { createEventDispatcher } from 'svelte';
  import * as mathlive from 'mathlive'
  let mf;
  const dispatch = createEventDispatcher();
  const ENTER = 13;
  function onKeyDown(event) {
    if(event.keyCode === ENTER && event.shiftKey) {
      event.preventDefault();
      dispatch('message', {
        cell: event.target.value
      });
    }
  }
</script>

<math-field on:keydown={onKeyDown} bind:this="{mf}"></math-field>

<style>
    math-field {
        border: 1px solid palegreen;
        padding: 0.5rem;
        font: inherit;
    }
</style>